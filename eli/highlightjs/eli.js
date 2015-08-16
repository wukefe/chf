/*
   Language: ELI
     Author: Hanfeng Chen <hanfeng.chen@mail.mcgill.ca>
Description: ELI - A System for Programming Arrays
    Website: http://fastarray.appspot.com/default.html
*/
function(hljs) {
  var ELI_KEY_WORDS={
	  keyword:  'if else while switch break continue',
	  built_in: 'key value first last meta xkey cols keys fkeys'
  };
  return {
  case_insensitive: true,
  aliases:['esf'],
  keywords: ELI_KEY_WORDS,
  lexemes: '[a-z][a-zA-Z0-9_]*[a-z]',
  contains: [
  {
	  className: 'string',
	  begin: "'", end: "'"
  },
  { // function still doesn't work
	  className: 'function',
	  begin: '@.', end: '@.'
	  //begin: '\\b@.', end:'@.'
  },
  hljs.C_LINE_COMMENT_MODE
     ]
  };
}
