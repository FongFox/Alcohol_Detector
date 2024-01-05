package com.alcoholdetector.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
//import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.alcoholdetector.entity.Admin;
import com.alcoholdetector.service.IAuthenticateService;

@RestController
@RequestMapping("/test")
public class TestController {
	@Autowired
	private IAuthenticateService authenticateService;
	
	@GetMapping("/")
	public String sayHello() {
		return "Hello World from Spring!";
	}
	
	@PostMapping("/login")
	public Object authenticate(@RequestBody Admin tempAdmin) {
		Admin dbAdmin = authenticateService.handleCheckLogin(tempAdmin);
		Object message = "Password not matched!!!";
		if(dbAdmin == null) {
			return message;
		}
		return dbAdmin;
	}
}
