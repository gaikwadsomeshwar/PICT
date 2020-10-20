delimiter //

CREATE TRIGGER customerdeletelog
BEFORE delete
on customer FOR each row
BEGIN

  insert into customer_log(cust_id,oldfname,newfname,oldlname,newlname,oldzipcode,newzipcode,oldphone_no,newphone_no,user,tstamp) values(OLD.cust_id,OLD.fname,"",OLD.lname,"",OLD.zipcode,"",OLD.phone_no,"",current_user(),current_timestamp());

END //

delimiter ;
