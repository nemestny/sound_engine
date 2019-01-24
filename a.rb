include Math

def pwm (args)
  angle = args[:angle]
  level = args[:level]
  v = angle*PI/180
  (sin(v)*level).to_i
end

def delta_x frequency
  frequency_pwm = 31372
  t_wave = 1.0/(frequency)
  t_pwm = 1.0/frequency_pwm
  n = t_wave/t_pwm
  delta_x = 180/n
  {n: n, delta_x: delta_x}
end

frequency_first_wave = 43
level_first_wave = 5
frequency_second_wave = frequency_first_wave*3
level_second_wave = 100

delta_first_wave = delta_x(frequency_first_wave)[:delta_x]
n_first_wave = delta_x(frequency_first_wave)[:n]
delta_second_wave = delta_x(frequency_second_wave)[:delta_x]
n_second_wave = delta_x(frequency_second_wave)[:n]

puts "frequency_first: #{frequency_first_wave}, level: #{level_first_wave}"
puts "frequency_second: #{frequency_second_wave}, level: #{level_second_wave}"

first_wave = 0
second_wave = 0

arr = []

0.upto(n_first_wave) do |n|
  arr << pwm(angle: first_wave, level: level_first_wave) + pwm(angle: second_wave, level: level_second_wave)
  first_wave+=delta_first_wave
  second_wave+=delta_second_wave
  delta_first_wave = -delta_first_wave if first_wave > 90 || first_wave <0
  delta_second_wave = -delta_second_wave if second_wave > 90 || second_wave <0
end

str = 0
arr.each do |num|
  print " #{num},"
  str+=1
  puts if str%25==0
end
puts
# p arr
puts "count of numbers: #{arr.length}"
