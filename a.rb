=begin
a = [1,2,5,7,10,12,15,17,19,22,24,27,30,32,34,37,39,42,
44,47,49,52,54,57,59,61,64,66,69,71,73,76,78,80,83,85,88,90,92,94,97,99,
101,103,106,108,110,113,115,117,119,121,124,126,128,130,132,134,136,138,140,142,144,146,
148,150,152,154,156,158,160,162,164,166,168,169,171,173,175,177,178,180,182,184,185,187,188,190,192,193,
195,196,198,199,201,202,204,205,207,208,209,211,212,213,215,216,217,219,220,221,222,223,224,225,226,227,
228,229,230,231,232,233,234,235,236,237,237,238,239,240,240,241,242,242,243,243,244,244,245,245,246,246,
247,247,247,248,248,248,248,249,249,249,249,249,255,255,255,255,249,249,249,249,249,248,
248,248,248,247,247,247,246,246,245,245,244,244,243,243,242,242,241,240,240,239,238,237,237,236,235,234,
233,232,231,230,229,228,227,226,225,224,223,222,221,220,219,217,216,215,213,212,211,209,208,207,205,204,
202,201,199,198,196,195,193,192,190,188,187,185,184,182,180,178,177,175,173,171,169,168,166,164,162,160,
158,156,154,152,150,148,146,144,142,140,138,136,134,132,130,128,126,124,121,119,117,115,113,110,108,106,
103,101,99,97,94,92,90,88,85,83,80,78,76,73,71,69,66,64,61,59,57,54,52,49,47,44,42,39,37,34,32,30,
27,24,22,19,17,15,12,10,7,5,2,1]
p a.map {|n| n/10 + 1}
=end
include Math

def pwm (args)
  angle = args[:angle]
  level = args[:level]
  v = angle*PI/180
  (sin(v)*level).to_i# + rand((level/10 + 1).to_i)
  # rand((level/10 + 1).to_i)
end

def delta_x frequency
  frequency_pwm = 31372
  t_wave_half = 1.0/(frequency) #*2
  t_pwm = 1.0/frequency_pwm
  n = t_wave_half/t_pwm
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

# while first_wave<90
#   arr << pwm(angle: first_wave, level: level_first_wave)
#   first_wave+=delta_first_wave
# end

# while first_wave>0
#   arr << pwm(angle: first_wave, level: level_first_wave)
#   first_wave-=delta_first_wave
# end
str = 0
arr.each do |num|
  print " #{num},"
  str+=1
  puts if str%25==0
end
puts
# p arr
puts "count of numbers: #{arr.length}"
