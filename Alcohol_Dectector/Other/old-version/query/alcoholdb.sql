create database alcoholdb;
use alcoholdb;

create table person(
	ID int not null auto_increment,
    p_ID int null,
    p_LName varchar(255),
    p_MName varchar(255),
    p_FName varchar(255),
    p_StatusIndex float,
    p_Status varchar(255),
    -- s_id int,
    constraint pk_person primary key (ID),
    constraint uc_person unique (p_ID)
);

-- create table sensor(
-- 	id int not null auto_increment,
--     s_id int null,
--     s_normal float,
--     s_drunklegal float,
--     s_drunkillegal float,
--     constraint pk_sensor primary key (id, s_id)
-- );

select * from person;
insert into person (p_ID, p_LName, p_MName, p_FName, p_StatusIndex, p_Status) 
	values ('p_ID','p_LName','p_MName','p_FName',p_StatusIndex,'p_Status');

update person set p_ID = 'p_ID', p_LName = 'p_LName', p_MName = 'p_MName', p_FName = 'p_FName' where id = id;
delete from person where id = id;
delete from person where ID = 3;