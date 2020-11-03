DELIMITER //

CREATE PROCEDURE phoneList (INOUT phnoList varchar(4000))

BEGIN

  DECLARE finished INTEGER DEFAULT 0;
	DECLARE phno varchar(100) DEFAULT "";

	-- declare cursor for customer phone no
	DEClARE curPhNo
		CURSOR FOR
			SELECT phone_no FROM customer;

	-- declare NOT FOUND handler
	DECLARE CONTINUE HANDLER
        FOR NOT FOUND SET finished = 1;

	OPEN curPhNo;

	getPhNo: LOOP

		FETCH curPhNo INTO phno;

    IF finished = 1 THEN
			LEAVE getPhNo;
		END IF;

    -- build phone list
		SET phnoList = CONCAT(phno,";",phnoList);

	END LOOP getPhNo;

  CLOSE curPhNo;

END //

DELIMITER ;
