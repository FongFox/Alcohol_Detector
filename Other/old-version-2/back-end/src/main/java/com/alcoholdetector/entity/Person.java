package com.alcoholdetector.entity;

import java.util.Date;

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
@Table(name = "person")
@NoArgsConstructor
@Getter @Setter
@ToString
public class Person {
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	@Column(name = "id")
	private int id;
	@Column(name = "driver_license_id")
	private Long driverLicenseId;
	@Column(name = "person_id")
	private Long personId;
	@Column(name = "person_name")
	private String personName;
	@Column(name = "person_dob")
	private Date personDOB;
	@Column(name = "alcohol_value")
	private Double alcoholValue;
	@Column(name = "create_at")
	private Date createAt;
}
