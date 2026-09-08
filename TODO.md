# TODO

- [ ] Benchmark `selection_sort_asc_filinfo` against a quicksort implementation
  for directory entries. MOS uses C `qsort()` internally for `DIR`/`LS`, but
  does not expose that sorter through its application API, so evaluate porting
  or linking an equivalent implementation rather than assuming it can be
  called through MOS. Compare representative small and large music directories,
  and include execution time, code size, working memory, sort order, and the
  directories-before-files behavior before deciding whether to replace the
  current in-place selection sort.
