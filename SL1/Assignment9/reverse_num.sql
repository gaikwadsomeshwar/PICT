delimiter //

CREATE PROCEDURE reverse_num(num INT)
BEGIN

  DECLARE rev INT;
  DECLARE rem INT;
  DECLARE temp INT;

  SET rev=0;
  SET rem=0;
  SET temp=num;

  WHILE temp>0 DO

    SET rem=temp%10;
    SET rev=(rev*10)+rem;
    SET temp=floor(temp/10);

  END WHILE;

  SELECT num,rev;

END //

delimiter ;
