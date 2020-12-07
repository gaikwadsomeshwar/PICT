delimiter //

CREATE PROCEDURE even_odd_count(num INT)
BEGIN

  DECLARE inc INT;
  DECLARE countEven INT;
  DECLARE countOdd INT;

  SET inc=1;
  SET countEven=0;
  SET countOdd=0;

  WHILE inc<=num DO
    IF(inc MOD 2) THEN
      SET countOdd=countOdd+1;
    ELSE
      SET countEven=countEven+1;
    END IF;
    SET inc=inc+1;
  END WHILE;
  SELECT countEven,countOdd;

END //

delimiter ;
