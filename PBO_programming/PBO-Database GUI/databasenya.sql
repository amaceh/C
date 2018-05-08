create database gui_mvc;
use gui_mvc;

create table daftar_telepon(
	kode_anggota varchar(10) primary key,
	no_telp varchar(20)
);

insert into daftar_telepon values
	('T01','087823787287'),
	('T02','087823787288');