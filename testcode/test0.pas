program ProgramName;
const
	a = 10;
type
        int=Integer;
        long=Integer;
        gao=record
        g : Integer;
        end;
var
	i,variableName: int;
	x,y,z:real;

begin
	i := 0;
	goto 0000;
	9999:Main(i,i);
	i := 0;

	goto 9999;

	i := 0;
	Main(i,i);
	i := 0;
	goto 9999;

write(i);
end.
