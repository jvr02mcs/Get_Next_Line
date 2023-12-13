#ARQUITECTURA
arch=$(uname -a)
#NUCLEOS FISICOS!!!!!
#MEMORIA RAM !!!!!!!!!!!!!!!!!!
av_mem=$(free --mega | awk '$1 == "Mem:" {print $3}')
total_mem=$(free --mega |awk '$1 == "Mem:" {print $2}')
por_use=$(echo "(($mem_total - $mem_disponible) / $mem_total) * 100" | bc)
#DISK
disk_info=$(df -m | awk '"Mem:" {
    disk_total += $2
    disk_used += $3
}
END {
    disk_percent = (disk_used / disk_total) * 100
    printf "%d MB / %d GB (%.2f%%)\n", disk_used, disk_total/1024, disk_percent
}')
#ULTIMO REINICIO
last_boot=$(who -b | awk '$1 == "system" {print $3 " " $4 " " $5}')
#LVM!!!!
if lvdisplay &> /dev/null; then
  is_lvm_on=$(echo "is active on the system.")
else
  is_lvm_on=$(echo "isn't active on the system.")
fi
#CONEXIONES ACTIVAS !!!!!!!!!!!!!!!!!!!!!!!!
active_con=$(netstat -ta | grep -cE  '\s[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+:[0-9]+\s+[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+:[0-9]+\s+ESTABLISHED')
#!!!!!ss -ta | grep ESTAB | wc -l
#USERS
n_users=$(users | wc -w)
wall "Architecture : $arch
Avaliable RAM : $av_mem / $total_mem ($por_use)
Last boot : $last_boot
Disk : $disk_info
LVM $is_lvm_on
Active connections : $active_con
Number of users : $n_users"