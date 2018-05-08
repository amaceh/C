create database gui_crud;
use gui_crud;

create table daftar_buku(
	kode_buku int(4) primary key auto_increment,
	judul_buku varchar(40),
	penulis_buku varchar(40)
);

insert into daftar_buku values
	('','Mockingjay', 'Suzanne Collins'),
	('','My Wonderful Wizard of Oz', 'L. Frank Baum'),
	('','The Boy in the Stripes Pajamas', 'John Boyne'),
	('','I Am Ok You Are Ok', 'Thomas Harris'),
	('','Norwegian Wood', 'Haruki Murakami'),
	('','The Day I Swapped My Dad for Two Goldfish', 'Neil Gaiman'),
	('','Demian', 'Herman Hesse');