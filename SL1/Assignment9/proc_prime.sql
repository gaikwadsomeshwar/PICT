delimiter //

create procedure prime(num int)
begin

	declare i int;
	declare f int;
	declare msg varchar(100);

	set f = 0;
	set i = 2;
	set msg = '';

	label1: while i <= num/2 do
		if (num mod i) then
			set f = 1;
			LEAVE label1;
		end if;
		set i = i + 1;
	end while;

	if (num = 1) then
		set msg = '1 is neither prime nor composite!';
	elseif (f = 0) then
		set msg = 'Prime number!';
	else
		set msg = 'Composite number!';
	end if;

	select msg;

end //

delimiter ;
