package com.alcoholdetector.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.alcoholdetector.entity.Admin;

@Repository
public interface AdminRepository extends JpaRepository<Admin, Integer>{
	public boolean existsByName(String name);
	public Admin findByName(String name);
}
