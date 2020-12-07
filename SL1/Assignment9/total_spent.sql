delimiter //

CREATE PROCEDURE total_spent(IN customerid INT, OUT total FLOAT)
BEGIN

  SELECT SUM(total_price) INTO total
  FROM orders
  where orders.cust_id=customerid;

END //

delimiter ;
