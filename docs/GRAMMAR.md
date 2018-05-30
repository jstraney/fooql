# Grammar

<pre>

<statement>:
  <(> ( <select_statement> | <insert_statement> | <delete_statement> | <update_statement> ) <)> <;> |
  <select_statement> | <insert_statement> | <delete_statement> | <update_statement> <;> |

<select_statement> :
  <SELECT>
  <expression> [, <expression>]
  (<FROM> <identifier> [, <identifier>]){0,1}
  [< * JOIN><identifier> <ON> <expression>]
  (<WHERE> <expression> ([<AND> | <OR>] <expression>)){0,1}
  [<GROUP BY> <identifier>[<HAVING>] <expression>]
  (<ORDER BY> <identifier> (<ASC> | <DESC>)

<insert_statement> :
  <INSERT> <INTO> <identifier> <(> <identifier>+ <)> <VALUES> <(> <value>+ <)> 

<update_statement> :
  <UPDATE> <identifier> [<SET> ];

<expression> : <comparison> | <term> | <product> [[<+><->] <product>] | <(> <product> [[<+><->] <product>] <)>
<comparison> : <term> <rel-operator> <term>
<product>    : <term> [ / * ] <term> |  <term>
<term>       : <value> | <identifier>
<value>      : <bool> | <number> | <string>
<bool>       : TRUE | FALSE
<number>     : [x | 0][1-9]+[0-9]+[.[0-9]+]
<string>     : "[UTF-8]"
<identifier> : [a-zA-Z_] +[a-zA-Z0-9_]+
<rel-operator> : >, >=, =, <, <=, <>
<(> : (
<)> : )
<[> : [
<]> : ]
<+> : +
<-> : - 
<*> : * 
</> : /

<BEGIN>    : BEGIN
<END>      : END
<SELECT>   : SELECT 
<DELETE>   : DELETE 
<UPDATE>   : UPDATE 
<INTO>     : INTO
<FROM>     : FROM 
<OUTER JOIN> : <OUTER> <JOIN>   
<INNER JOIN> : <INNER> <JOIN>   
<LEFT JOIN>  : <LEFT>  <JOIN>  
<RIGHT JOIN> : <RIGHT> <JOIN> 
<JOIN>     : JOIN 
<WHERE>    : WHERE 
<GROUP BY> : <GROUP> <BY>
<ORDER BY> : <ORDER> <BY>
<GROUP>    : GROUP
<ORDER>    : ORDER 
<ASC>      : ASC
<DESC>     : DESC 
<ON>       : ON 
<AND>      : AND
<OR>       : OR 
<;>        : ;
</pre>
