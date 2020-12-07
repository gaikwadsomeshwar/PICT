delimiter //

CREATE PROCEDURE tax_calculation(IN sal FLOAT)
BEGIN

  DECLARE hra FLOAT;
  DECLARE medAll FLOAT;
  DECLARE it FLOAT;
  DECLARE net FLOAT;

  SET hra=sal*0.1;
  SET medAll=sal*0.05;
  SET it=sal*0.2;
  SET net=sal-hra-medAll-it;

  SELECT sal,hra,medAll,it,net;

END //

delimiter ;
