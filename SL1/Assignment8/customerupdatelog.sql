delimiter //

CREATE TRIGGER customerupdatelog
AFTER update
on customer FOR each row
BEGIN

  insert into customer_log(cust_id,oldfname,newfname,oldlname,newlname,oldzipcode,newzipcode,oldphone_no,newphone_no,user,tstamp) values(OLD.cust_id,OLD.fname,NEW.fname,OLD.lname,NEW.lname,OLD.zipcode,NEW.zipcode,OLD.phone_no,NEW.phone_no,current_user(),current_timestamp());

END //

delimiter ;
