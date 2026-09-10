"""Use the existing canonical Agon converters/writer/parser unchanged."""

import hashlib
import importlib.util
import json
import sys
from pathlib import Path

import agonutils

ROOT=Path(__file__).resolve().parent


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def load_module(name,path):
    spec=importlib.util.spec_from_file_location(name,path)
    module=importlib.util.module_from_spec(spec);sys.modules[name]=module
    spec.loader.exec_module(module)
    return module


def canonical(utils):
    lock=json.loads((ROOT/'toolchain.json').read_text())
    for path,expected in lock['files'].items():
        if sha(utils/path)!=expected:
            raise ValueError(f'Canonical tool source changed: {path}')
    if sha(agonutils.__file__)!=lock['extension_sha256']:
        raise ValueError('Canonical agonutils extension changed')
    writer=load_module('skin012_writer',utils/'examples/agnb/images/container/scripts/do_assembly.py')
    viewer=load_module('skin012_viewer',utils/'examples/agnb/images/container/scripts/view_agnb.py')
    palette=utils/'examples/slideshow/palettes/Agon64.gpl'
    return writer,viewer,palette
