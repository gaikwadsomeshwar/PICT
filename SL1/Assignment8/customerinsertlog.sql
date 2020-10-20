delimiter //

CREATE TRIGGER customerinsertlog
AFTER insert
on customer FOR each row
BEGIN

  insert into customer_log(cust_id,oldfname,newfname,oldlname,newlname,oldzipcode,newzipcode,oldphone_no,newphone_no,user,tstamp) values(NEW.cust_id,NULL,NEW.fname,NULL,NEW.lname,NULL,NEW.zipcode,NULL,NEW.phone_no,current_user(),current_timestamp());

END //

delimiter ;
