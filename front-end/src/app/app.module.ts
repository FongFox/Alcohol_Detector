import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { HttpClientModule } from '@angular/common/http';
import { FormsModule } from '@angular/forms';

import { NgxPaginationModule } from 'ngx-pagination';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { PersonsComponent } from './component/persons/persons.component';
import { PageNotFoundComponent } from './component/page-not-found/page-not-found.component';
import { AboutComponent } from './component/about/about.component';
import { DetectComponent } from './component/detect/detect.component';
import { PersonFormComponent } from './component/person-form/person-form.component';
import { BrowserAnimationsModule } from '@angular/platform-browser/animations';

@NgModule({
  declarations: [
    AppComponent,
    PersonsComponent,
    PageNotFoundComponent,
    AboutComponent,
    DetectComponent,
    PersonFormComponent,
  ],
  imports: [
    BrowserModule,
    NgxPaginationModule,
    FormsModule,
    AppRoutingModule,
    HttpClientModule,
    BrowserAnimationsModule
  ],
  providers: [],
  bootstrap: [AppComponent],
})
export class AppModule {}
