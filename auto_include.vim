
function! UnfoldIncludeFiles()
  pyfile unfold_includes.py
endfunction

function! AddNeededIncludes()
  pyfile add_includes.py
endfunction

function! PrepareForSending()
  call AddNeededIncludes()
  call UnfoldIncludeFiles()
endfunction
