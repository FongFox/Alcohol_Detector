package com.alcoholdetector.entity;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.Table;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.ToString;

@Entity
@Table(name = "admin")
@NoArgsConstructor
@Getter @Setter
@ToString
public class Admin {
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	@Column(name = "id")
	private int id;
	@Column(name = "name")
	private String name;
	@Column(name = "password")
	private String password;
	@Column(name = "isAdmin")
	private Boolean isAdmin;
	@Column(name = "isLogged")
	private Boolean isLogged;
	
	public Admin(String name, String password, Boolean isAdmin) {
		super();
		this.name = name;
		this.password = password;
		this.isAdmin = isAdmin;
	}
	
	
}
