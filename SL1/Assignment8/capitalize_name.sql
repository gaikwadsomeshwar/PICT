delimiter //

create TRIGGER capitalize_name
before insert
on customer for each row
begin

  set NEW.fname= CONCAT((UPPER(SUBSTRING(NEW.fname, 1, 1))),SUBSTR(NEW.fname, 2));
  set NEW.lname= CONCAT((UPPER(SUBSTRING(NEW.lname, 1, 1))),SUBSTR(NEW.lname, 2));

 end //

delimiter ;
