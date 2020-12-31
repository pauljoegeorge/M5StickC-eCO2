greet = Greet.new
while true
  # puts greet.hola
  if button_a_pressed?
    puts "Button A pressed"
    put_color(0, 30, 160, 100, "RED");
    put_string(60, 60, "BUTTON A");
  end
  if button_b_pressed?
    puts "Button B pressed"
    put_color(0, 30, 160, 100, "GREEN");
    put_string(60, 60, "BUTTON B");
  end
  sleep 0.3
end
