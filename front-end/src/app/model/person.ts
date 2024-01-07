export interface Person {
  _id: number; //this is the id in db (with p/key & auto increment)
  id: number; //person id card
  driverId: number; //driver license id
  name: string; //person name
  dob: Date; //person date of birth
  gender: string;
  alcoholValue: number; //alcohol value
  createAt: Date; //create at
}
