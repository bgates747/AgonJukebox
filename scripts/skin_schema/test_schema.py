"""Contract rejection tests plus accepted-definition checks; no hardware access."""
from pathlib import Path
import copy,json,shutil,sys,tempfile,unittest
sys.path.insert(0,str(Path(__file__).resolve().parent))
from validate import load_definition,DefinitionError
ROOT=Path(__file__).resolve().parents[2]
class SchemaTests(unittest.TestCase):
    def setUp(self):
        self.tmp=tempfile.TemporaryDirectory();self.root=Path(self.tmp.name)
        shutil.copytree(ROOT/'src/skins/seventies/prepared',self.root/'prepared')
        shutil.copy2(ROOT/'src/skins/seventies/source.png',self.root/'source.png')
        self.d=json.loads((ROOT/'src/skins/seventies/skin.json').read_text());self.path=self.root/'skin.json'
    def tearDown(self):self.tmp.cleanup()
    def check(self,d=None):
        self.path.write_text(json.dumps(d or self.d));return load_definition(self.path)
    def test_accepted_definitions(self):
        for skin in ('artdeco','seventies'):self.assertEqual(load_definition(ROOT/'src/skins'/skin/'skin.json')['id'],skin)
    def test_invalid_contracts(self):
        mutations=[
          lambda d:d.update(schema_version=2),lambda d:d.update(id='../escape'),
          lambda d:d.update(extra=True),lambda d:d.update(backdrop='../elsewhere.png'),
          lambda d:d['palette'].update(background=[84,0,0]),
          lambda d:d['widgets'][0].update(n=61),lambda d:d['widgets'][0].update(x=510),
          lambda d:d['widgets'].pop(),lambda d:d['widgets'].append(copy.deepcopy(d['widgets'][0])),
          lambda d:d['playlist'].update(filename_columns=55),
          lambda d:d['playlist'].update(filename_columns=6),
          lambda d:d['playlist'].update(duration_offset=40),
          lambda d:d['selection'].update(x=510),lambda d:d.update(progress_span=250),
          lambda d:d['assets'][0].update(name='bad_state'),lambda d:d['fonts'].update(small='source.png'),
          lambda d:d['review']['test'].update(w_play='tile_000'),
          lambda d:d['review']['test'].update(selected=10),lambda d:d.update(runtime_format='other'),
        ]
        for mutate in mutations:
            d=copy.deepcopy(self.d);mutate(d)
            with self.subTest(mutation=mutations.index(mutate)),self.assertRaises(DefinitionError):self.check(d)
    def test_duplicate_json_keys(self):
        self.path.write_text('{"schema_version":1,"schema_version":2}')
        with self.assertRaisesRegex(DefinitionError,'duplicate'):load_definition(self.path)
    def test_large_status_contract(self):
        for w in self.d['widgets']:
            if w['kind']=='text' and not w['name'].startswith('w_row'):
                w['cell']=[6,12]
                w['x']=min(w['x'],512-w['n']*6)
                w['rect']=[w['x'],w['y'],w['n']*6,12]
        self.check()
        short=copy.deepcopy(self.d);short['widgets'][0]['rect'][3]=8
        with self.assertRaisesRegex(DefinitionError,'exceeds restoration'):self.check(short)
        mixed=copy.deepcopy(self.d);mixed['widgets'][0]['cell']=[5,8]
        with self.assertRaisesRegex(DefinitionError,'common font'):self.check(mixed)
        wrong=copy.deepcopy(self.d);wrong['widgets'][0]['fg']=[255,255,255]
        with self.assertRaisesRegex(DefinitionError,'glyph colors'):self.check(wrong)
    def test_palette_must_match_glyph_background(self):
        self.d['palette']['selection']=[255,85,0]
        with self.assertRaisesRegex(DefinitionError,'space glyph'):self.check()
    def test_input_symlink_cannot_escape(self):
        external=self.root.parent/(self.root.name+'-outside');external.write_bytes(b'x')
        try:
            (self.root/'outside').symlink_to(external);self.d['source']='outside'
            with self.assertRaisesRegex(DefinitionError,'escapes'):self.check()
        finally:external.unlink()
if __name__=='__main__':unittest.main()
