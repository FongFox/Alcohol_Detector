import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { PageNotFoundComponent } from './component/page-not-found/page-not-found.component';
import { AboutComponent } from './component/about/about.component';
import { DetectComponent } from './component/detect/detect.component';
import { PersonsComponent } from './component/persons/persons.component';

const routes: Routes = [
  { path: 'persons', component: PersonsComponent },
  { path: 'detect', component: DetectComponent },
  { path: 'about', component: AboutComponent },
  { path: '', redirectTo: '/persons', pathMatch: 'full' },
  { path: '**', component: PageNotFoundComponent }, // Wildcard route for a 404 page
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
