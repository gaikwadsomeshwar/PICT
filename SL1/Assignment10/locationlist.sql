DELIMITER //

CREATE PROCEDURE locationlist (INOUT locList varchar(4000))

BEGIN

  DECLARE finished INTEGER DEFAULT 0;
	DECLARE loc varchar(100) DEFAULT "";

	DEClARE curLoc
		CURSOR FOR
			SELECT city FROM customer;

	-- declare NOT FOUND handler
	DECLARE CONTINUE HANDLER
        FOR NOT FOUND SET finished = 1;

	OPEN curLoc;

	getLoc: LOOP

		FETCH curLoc INTO loc;

    IF finished = 1 THEN
			LEAVE getLoc;
		END IF;

    IF (LOCATE(loc,locList)=0) THEN
		  SET locList = CONCAT(loc,";",locList);
    END IF;

	END LOOP getLoc;

  CLOSE curLoc;

END //

DELIMITER ;
