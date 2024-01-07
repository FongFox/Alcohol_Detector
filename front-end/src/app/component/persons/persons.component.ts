import { Component } from '@angular/core';
import { Person } from 'src/app/model/person';
import { PersonService } from 'src/app/services/person.service';

@Component({
  selector: 'app-persons',
  templateUrl: './persons.component.html',
  styleUrls: ['./persons.component.css']
})
export class PersonsComponent {
  persons: Person[] = [];
  p: string|number|undefined;

  constructor(private service: PersonService) {}

  ngOnInit(): void {
    //Called after the constructor, initializing input properties, and the first call to ngOnChanges.
    //Add 'implements OnInit' to the class.
    this.getDummyData();
  }

  getDummyData(){
    this.service.getDummyData().subscribe(res => {
      this.persons = res;
      // console.log(this.persons);
    });
  }
}
