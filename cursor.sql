-- 1)

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

-- Enter value for a: 1000000
-- old  12:        if c_sal<&a then
-- new  12:        if c_sal<1000000 then
-- Wu   finance   118800
-- Einstein   physics   104500
-- El Said   history   69300
-- Gold   physics   95700
-- Katz   comp.sci   86625
-- Califieri   history   71610
-- Crick   biology   83160
-- Brandt   comp.sci   101200
-- Kim   elec.eng   88000
-- Srinivasan   comp.sci   65000
-- Singh   finance   100000
---------------------------------------------------------------------------------------------------------

-- 2)

create view instr_count as select d.dept_name,count(*) as number_of_instr from department d,instructor i where d.dept_name=i.dept_name group by d.dept_name;
create view course_count as select d.dept_name,count(*) as number_of_course from department d,course c where d.dept_name=c.dept_name group by d.dept_name;

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

-- biology   1   3
-- finance   2   2
-- elec.eng   1   1
-- comp.sci   3   5
-- physics   2   1
-- history   2   1
-----------------------------------------------------------------------------------------------------------------

-- 3)

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

-- 12121   Wu   118800
-- 22222   Einstein   104500
-- 83821   Brandt   101200
-- 76543   Singh   100000
-- 33456   Gold   95700
------------------------------------------------------------------------------------------------

declare
iid instructor.id%type;
sal instructor.salary%type;
cursor c is select id,salary from instructor where dept_name='Comp.Sci.';
begin
open c;
loop
fetch c into iid,sal;
exit when c%notfound;
if(sal<80000) then
update instructor set salary=salary+(salary*.2) where id=iid;
else
update instructor set salary=salary+(salary*.12) where id=iid;
end if;
end loop;
close c;
end;
/
-- PL/SQL procedure successfully completed.

-- SQL> select id,salary from instructor;

--         ID     SALARY
-- ---------- ----------
--      12121     118800
--      22222     104500
--      32343      69300
--      33456      95700
--      45565      86625
--      58583      71610
--      76766      83160
--      83821     101200
--      98345      88000
--      10101      65000
--      76543     100000

-- 11 rows selected.
-----------------------------------------------------------------------

declare
i number:=0;
v takes%rowtype;
cursor c is select * from takes;
begin
open c;
loop
fetch c into v;
exit when c%notfound;
i:=i+1;
if(v.grade='A') then
dbms_output.put_line(v.id||' '||v.course_id||' '||v.sec_id||' '||v.semester||' '||v.year||' '||v.grade||chr(10));
end if;
end loop;
close c;
dbms_output.put_line('Total rows = '||i);
end;
/

-- 128 cs-101 1 fall 2010 A
-- 12345 cs-190 2 spring 2009 A
-- 12345 cs-315 1 spring 2009 A
-- 12345 cs-347 1 fall 2009 A
-- 76543 cs-101 1 fall 2010 A
-- 76543 cs-319 2 spring 2010 A
-- 98988 bio-101 1 summer 2009 A
-- Total rows = 20
-- PL/SQL procedure successfully completed.