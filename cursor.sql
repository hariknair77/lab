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
---------------------------------------------------------------------------------------------------------

create view instr_count as select d.dept_name,count(*) as number_of_instr from department d,instructor i where d.dept_name=i.dept_name group by d.dept_name;
create view course_count as select d.dept_name,count(*) as number_of_course from department d,course c where d.dept_name=c.dept_name group by d.dept_name;

select instr_count.number_of_instr,course_count.number_of_course from instr_count natural join course_count;

select instr_count.dept_name,instr_count.number_of_instr,course_count.number_of_course from instr_count inner join course_count on instr_count.dept_name = course_count.dept_name;

declare
c_dept instr_count.dept_name%type;
c_inst instr_count.number_of_instr%type;
c_course course_count.number_of_course%type;
cursor c_count is select instr_count.dept_name,instr_count.number_of_instr,course_count.number_of_course from instr_count inner join course_count on instr_count.dept_name = course_count.dept_name;
begin
open c_count;
loop
	fetch c_count into c_dept,c_inst,c_course;
	exit when c_count%notfound;
		dbms_output.put_line(c_dept||'   '||c_inst||'   '||c_course);
end loop;
close c_count;
end;
/
-----------------------------------------------------------------------------------------------------------------
declare
c_sal instructor.salary%type;
c_id instructor.id%type;
c_name instructor.name%type;
c number := 0;
cursor sal is  select id,name,salary from instructor order by salary desc;
begin
open sal;
loop
	fetch sal into c_id,c_name,c_sal;
	c := c+1;
	exit when c>5;
	dbms_output.put_line(c_id||'   '||c_name||'   '||c_sal);	
end loop;
close sal;
end;
/

