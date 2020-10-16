delimiter //

CREATE TRIGGER check_quantity
BEFORE insert
on selects FOR each row
BEGIN

  IF NEW.quantity<=0 THEN
    SIGNAL SQLSTATE '80000'
        SET MESSAGE_TEXT = 'Quantity should be greater than 0';
  END IF;

END //

delimiter ;
