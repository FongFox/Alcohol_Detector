package com.alcoholdetector.service;

import com.alcoholdetector.entity.Admin;

public interface IAuthenticateService {
	public Admin handleCheckLogin(Admin tempAdmin); 
}
