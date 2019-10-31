create or replace trigger credit_update after update of credits on course for each row begin
  dbms_output.put_line('old credit: ' || :old.credits);
  dbms_output.put_line('new credit: ' || :new.credits);
  end;
/

SQL> update course set credits=7 where course_id='bio-101';
old credit: 4
new credit: 7
--------------------------------------------------------------------------------------
create table new_sal (id varchar(20),old_sal number,new_sal number);
create or replace trigger salary_update after update of salary on instructor for each row
begin
  insert into new_sal values(:old.id,:old.salary,:new.salary);
  dbms_output.put_line('salary diff : '|| (:new.salary-:old.salary));
end;
/
SQL> update instructor set salary=100000 where id=76543;
salary diff : 20000

1 row updated.

SQL> select *  from new_sal;

ID                      OLD_SAL    NEW_SAL
-------------------- ---------- ----------
76543                     80000     100000
---------------------------------------------------------------------------------------
create or replace trigger course_ins before insert on course for each row when(new.credits<3)
begin 
  RAISE_APPLICATION_ERROR(-20000,'oops credits cant be less than 3');
  end;
/
SQL> insert into course  values('eco-101','intro to economics','finance',2);

ORA-20000: oops credits cant be less than 3
ORA-06512: at "R577.COURSE_INS", line 2
ORA-04088: error during execution of trigger 'R577.COURSE_INS'

SQL> insert into course  values('eco-101','intro to economics','finance',10);

1 row created
-----------------------------------------------------------------------------------------------------------
create or replace trigger takes_trig before delete on takes for each row when(old.year = 2009 and old.semester='fall') 
  begin
  RAISE_APPLICATION_ERROR(-20000,'oops cant delete row with year=2009 and semester fall');
  end;
/

SQL> delete from takes where id=98765;

2 rows deleted.

SQL> delete from takes where id=12345;
delete from takes where id=12345
            *
ERROR at line 1:
ORA-20000: oops cant delete row with year=2009 and semester fall
ORA-06512: at "R577.TAKES_TRIG", line 2
ORA-04088: error during execution of trigger 'R577.TAKES_TRIG'
---------------------------------------------------------------------------------------
SQL> drop trigger credit_update;

Trigger dropped.

SQL> drop trigger salary_update;

Trigger dropped.

SQL> drop trigger course_ins;

Trigger dropped.

SQL> drop trigger takes_trig;

Trigger dropped.