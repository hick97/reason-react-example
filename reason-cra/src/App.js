import React, { useState } from "react";
import logo from "./logo.svg";
import { make as ButtonsSection } from "./reason/ButtonsSection.bs";
import "./App.css";

function App() {
  const [count, setCount] = useState(0)

  const handleIncrement = () => {
    setCount(prev => prev + 1)
  }

  const handleDecrement = () => {
    setCount(prev => prev - 1)
  }

  const handleReset = () => {
    setCount(0)
  }

  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          Counter: {count}
        </p>
        <ButtonsSection 
          handleIncrement={handleIncrement} 
          handleDecrement={handleDecrement} 
          handleReset={handleReset} 
        />
      </header>
    </div>
  );
}

export default App;
