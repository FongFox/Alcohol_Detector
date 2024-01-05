package com.alcoholdetector.service.impl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.alcoholdetector.entity.Admin;
import com.alcoholdetector.repository.AdminRepository;
import com.alcoholdetector.service.IAuthenticateService;

@Service
public class AuthenticateService implements IAuthenticateService {
	
	@Autowired
	private AdminRepository adminRepository; 

	@Override
	public Admin handleCheckLogin(Admin tempAdmin) {
		// TODO Auto-generated method stub
		Admin dbAdmin = adminRepository.findByName(tempAdmin.getName());
		if( tempAdmin.getPassword().compareTo(dbAdmin.getPassword()) == 0 ) {
			if(dbAdmin.getIsAdmin()) {
				return dbAdmin;
			}
		}
		
		return null;
	}
	
}
