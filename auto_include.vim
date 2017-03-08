if !has('python')
  finish
endif

function! UnfoldIncludeFiles()
  pyfile unfold_includes.py
endfunction

function! AddNeededIncludes()
  pyfile add_includes.py
endfunction
