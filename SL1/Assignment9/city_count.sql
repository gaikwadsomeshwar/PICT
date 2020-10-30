delimiter //

CREATE PROCEDURE city_count(IN cityname varchar(20), OUT total INT)
BEGIN

  SELECT COUNT(city) INTO total
  FROM customer
  where customer.city=cityname;

END //

delimiter ;
