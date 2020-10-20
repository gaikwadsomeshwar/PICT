delimiter //

CREATE TRIGGER orderdeletelog
BEFORE delete
on selects FOR each row
BEGIN

  insert into customer_log(order_id,product_id,oldquantity,newquantity,oldprice,newprice,user,tstamp) values(OLD.order_id,OLD.product_id,OLD.quantity,"",OLD.price,"",current_user(),current_timestamp());

END //

delimiter ;
