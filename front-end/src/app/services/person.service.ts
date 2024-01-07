import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Person } from '../model/person';
import { Observable } from 'rxjs';

@Injectable({
  providedIn: 'root',
})
export class PersonService {
  private dummyDataPath = '../../assets/json/dummy-data.json';
  persons: Person[] = [];

  constructor(private http: HttpClient) {}

  getDummyData(): Observable<Person[]> {
    return this.http.get<Person[]>(this.dummyDataPath);
  }
}
