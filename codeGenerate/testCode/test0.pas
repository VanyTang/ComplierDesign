program ProgramName;
const
	a = 10;
        str = 'abc';
type
        int=Integer;
        long=Integer;
        gao=record
            g : Integer;
        end;
        month = (jan, feb, dec);
        monthsub = feb..dec;
        myar = array[1..10] of real;
        myar1= array['a'..'z'] of int;
var
	i,variableName: int;
	x,y,z:real;
        ann : month;
        amm : monthsub;
procedure Main(a:Integer;var b: Integer);
begin
        writeln(a);
end;

function FunctionName: Integer;
begin

end;

begin

	i := a[0] + f(x,y,z)- 1 + (3-6)/2 + 2;
end.
