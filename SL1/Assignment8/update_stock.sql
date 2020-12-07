delimiter //

CREATE TRIGGER update_stock
BEFORE insert
on selects FOR each row
BEGIN

  IF (NEW.quantity>(select stock from product where NEW.product_id=product.product_id)) THEN
    SIGNAL SQLSTATE '80000'
        SET MESSAGE_TEXT = 'Order exceeding stock';
  ELSE
    update product set stock=stock-NEW.quantity where NEW.product_id=product.product_id;
  END IF;

END //

delimiter ;
