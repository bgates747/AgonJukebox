; Shared application composition; skin parameters are defined by the entry point.
    include "jukebox_modules.inc"
    if skin_seventies
    include "../ui/seventies/widgets.inc"
    endif
    if skin_artdeco-skin_seventies
    include "../ui/artdeco/widgets.inc"
    endif
    if 1-skin_artdeco
    include "ui_widgets.inc"
    endif
    include "jukebox_start.inc"
