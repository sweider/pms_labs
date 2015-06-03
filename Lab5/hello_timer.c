#include <linux/module.h>
#include <linux/init.h>
#include <linux/kobject.h>
#include <linux/sysfs.h>
#include <linux/string.h>
#include <linux/kernel.h> 
#include <linux/timer.h>

static int delay = -1;
struct timer_list timer;

static void hello(unsigned long arg) 
{
	printk(KERN_INFO "hello world!\n");
	timer.expires = jiffies + HZ*delay;
	add_timer (&timer);
}

static ssize_t show(struct kobject *kobj,
    struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "%d\n", delay);
}

static ssize_t store(struct kobject *kobj,
    struct kobj_attribute *attr, const char *buf, size_t count)
{
	int tmp = 0;
	sscanf(buf, "%du", &tmp);
	if(tmp > 0) {
		if(delay < 0) {
			init_timer (&timer);
			timer.function = hello;
			timer.data = 0;
			hello(0);
		}
		delay = tmp;
	}
	return count;
}

static struct kobj_attribute sc_attrb =
    __ATTR(timer, 0666, show, store);
static struct kobject *kobj;

static int __init example_init(void)
{
	kobj = kobject_create_and_add("hello", NULL);
	if (!kobj)
		return - ENOMEM;
	if(sysfs_create_file(kobj, &sc_attrb.attr)) 
		kobject_put(kobj);
	return 0;
}

static void __exit example_exit(void)
{
	del_timer (&timer);
	sysfs_remove_file(kobj, &sc_attrb.attr);
	kobject_put(kobj);
}

module_init(example_init);
module_exit(example_exit);

MODULE_LICENSE("GPL");
