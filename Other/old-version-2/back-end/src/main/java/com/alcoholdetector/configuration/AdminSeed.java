package com.alcoholdetector.configuration;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.context.annotation.Configuration;
import org.springframework.data.domain.Example;
import org.springframework.data.domain.ExampleMatcher;
import org.springframework.stereotype.Component;

import com.alcoholdetector.entity.Admin;
import com.alcoholdetector.repository.AdminRepository;
import com.fasterxml.jackson.databind.jsontype.BasicPolymorphicTypeValidator.NameMatcher;

@Configuration
public class AdminSeed implements CommandLineRunner{
	private final AdminRepository adminRepository;
	
	
	public AdminSeed(AdminRepository adminRepository) {
		super();
		this.adminRepository = adminRepository;
	}


	@Override
	public void run(String... args) throws Exception {
		// TODO Auto-generated method stub
		Admin root = new Admin("admin", "admin", true);
		
		if(adminRepository.existsByName(root.getName())) {
			System.out.println("========================================");
			System.out.println("Already have this admin account!");
		} else {
			System.out.println("Start Generate Admin");
			adminRepository.save(root);
			System.out.println("============= Complete ! ===============\n");	
		}
		
		System.out.println("Name: " + root.getName() + ", Password: " + root.getPassword());
        System.out.println("========================================\n");
	}

}
