# Canonical AGNB API snapshot

`agnb_api.inc` is an unchanged copy from
`https://github.com/bgates747/agon-utils`, commit
`434bf734a9f5a4cf84b4428f6a6be24d2bfc7b33`, path
`examples/agnb/api/agnb_api.inc`.

SHA256: `4693d4b17274e0c2476507cce98032e91cfa0d304317b2c8247b043d048dcccc`.
The upstream public-domain license is retained in `LICENSE`.

The canonical implementation is maintained in agon-utils. This snapshot makes
ordinary Jukebox checkouts build independently; update it from the canonical
source and requalify its consumers rather than maintaining a separate parser.
The app supplies MOS, math and VDU dependencies. Its previously missing audio
conversion helper, copied unchanged from `agnb_dependencies.inc`, is retained
in `src/asm/agnb_vdu.inc`. The Jukebox image consumer validates resource metadata
before invoking the canonical upload/finalize primitives.
