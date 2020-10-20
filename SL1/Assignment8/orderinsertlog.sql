delimiter //

CREATE TRIGGER orderinsertlog
AFTER INSERT
on selects FOR each row
BEGIN

  insert into customer_log(order_id,product_id,oldquantity,newquantity,oldprice,newprice,user,tstamp) values(NEW.order_id,NEW.product_id,"",NEW.quantity,"",NEW.price,current_user(),current_timestamp());

END //

delimiter ;
