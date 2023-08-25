import './App.css';
import React, { useState } from 'react';
import axios from 'axios';

export default class App extends React.Component {
  componentDidMount() {
    axios.get('http://192.168.2.8:8080/person')
      .then(res => {
        console.log(">>> check res: ", res);
      })
  }

  render() {
    return (
      // Status
      <>
        {/* Status */}
        <div className="status">
          <button type="button" className="btn btn-primary">Normal</button>
          <button type="button" className="btn btn-warning disabled">Drinking</button>
          <button type="button" className="btn btn-danger disabled">DRUNK</button>
          <button type="button" className="btn btn-light disabled">Begin</button>
        </div>
        <section>
          <div className="title">
            <h3>View Table</h3>
          </div>
          {/* data table */}
          <table className="table table-bordered">
            <thead>
              <tr>
                <th scope="col">Ngày</th>
                <th scope="col">STT</th>
                <th scope="col">Mã CCCD</th>
                <th scope="col">Họ</th>
                <th scope="col">Tên Đệm</th>
                <th scope="col">Tên</th>
                <th scope="col" class="setting">Thao Tác</th>
              </tr>
            </thead>
            <tbody>
              <tr>
                <td>01/01/1999</td>
                <td>1</td>
                <td>1</td>
                <td>Nguyễn</td>
                <td>Văn</td>
                <td>A</td>
                <td class="setting">
                  <a href="#">Thêm</a>
                  <a href="#">Sửa</a>
                  <a href="#">Xoá</a>
                </td>
              </tr>
            </tbody>
          </table>
        </section>
      </>
    );
  }
}
