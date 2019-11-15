declare
c_dept instructor.dept_name%type;
c_name instructor.name%type;
c_sal instructor.salary%type;
-- a number;
cursor c_instr is select dept_name,name,salary from instructor;
begin
open c_instr;
loop
	fetch c_instr into c_dept,c_name,c_sal;
	exit when c_instr%notfound;
	if c_sal<&a then
		dbms_output.put_line(c_name||'   '||c_dept||'   '||c_sal);
	end if;
end loop;
close c_instr;
end;
/

Enter value for a: 1000000
old  12:        if c_sal<&a then
new  12:        if c_sal<1000000 then
Wu   finance   118800
Einstein   physics   104500
El Said   history   69300
Gold   physics   95700
Katz   comp.sci   86625
Califieri   history   71610
Crick   biology   83160
Brandt   comp.sci   101200
Kim   elec.eng   88000
Srinivasan   comp.sci   65000
Singh   finance   100000
