create database db_stash;
	use db_stash;

create table `tb_courier`(
	item_name varchar(15) Primary key,
	item_buy varchar(20),
	item_sell varchar(20)
);

insert into tb_courier values
	('Difain Rapier', '6400', '0'),
	('Baterflai', '5200', '2600'),
	('Betel Fyuri', '4800', '2400'),
	('Mejik Stik', '200', '100'),
	('Heven Halbred', '2800', '1400'),
	('Cis', '0', '500');