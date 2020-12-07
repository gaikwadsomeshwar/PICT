delimiter //

CREATE TRIGGER calculate_price
BEFORE insert
on selects FOR each row
BEGIN

  SET  NEW.price=NEW.quantity*(select price from product where NEW.product_id=product.product_id);
  UPDATE orders SET total_price=total_price+NEW.price;

END //

delimiter ;
