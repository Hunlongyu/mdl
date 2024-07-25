<template>
    <div class="tools">
        <n-layout-header bordered class="tools-header">
            <n-popover trigger="hover">
                <template #trigger>
                    <n-button circle @click="videoMerge">
                        <n-icon size="18">
                            <MergeCells />
                        </n-icon>
                    </n-button>
                </template>
                <span>视频合并</span>
            </n-popover>
            <n-popover trigger="hover">
                <template #trigger>
                    <n-button circle @click="videoMerge">
                        <n-icon size="18">
                            <Unlock />
                        </n-icon>
                    </n-button>
                </template>
                <span>视频解密</span>
            </n-popover>
        </n-layout-header>
        <n-layout-content class="tools-content" :native-scrollbar="false">
            <n-data-table striped :columns="columns" :data="data" :pagination="false" :bordered="false"
                :row-key="(row) => row.key" @update:checked-row-keys="handleCheck" />
        </n-layout-content>
        <n-layout-footer bordered class="tools-footer">
            tools log
        </n-layout-footer>
    </div>
    <AddTask v-model="showModal" @addTaskConfirm="addTaskConfirm" />
</template>

<script setup>
import { ref } from 'vue'
import { NButton, useMessage } from 'naive-ui'
import { MergeCells, Unlock } from '@icon-park/vue-next'
import AddTask from '../components/addTask.vue'

const message = useMessage()

const data = ref([
    { key: "uuid1", name: "Wonderwall", process: "20%", speed: "1Mbps", status: "下载中", remainder: "12:04:18" },
    { key: "uuid2", name: "Don't Look Back in Anger", process: "60%", speed: "1Mbps", status: "下载中", remainder: "4:48" },
    { key: "uuid3", name: "Champagne Supernova", process: "100%", speed: "0Mbps", status: "合并中", remainder: "0:00" },
    { key: "uuid4", name: "I love you", process: "100%", speed: "0Mbps", status: "已完成", remainder: "0:00" }
])

const columns = [
    { type: "selection" },
    {
        title: "名称", key: 'name', align: "left", minWidth: 200,
        ellipsis: {
            tooltip: true
        }
    },
    { title: "进度", key: 'process', width: 100, align: "center" },
    { title: "速度", key: 'speed', width: 100, align: "center" },
    { title: "状态", key: 'status', width: 100, align: "center" },
    { title: "剩余时间", key: 'remainder', width: 100, align: "center" }
]

const checkedRowKeys = ref([]) // 选中的行

function handleCheck(rowKeys) {
    checkedRowKeys.value = rowKeys
}

const showModal = ref(false);

// 添加任务
function addTask() {
    showModal.value = true;
}

// 批量添加任务
function addBatchTask() { }

// 确认添加任务
function addTaskConfirm() {
    console.log("confirm")
    message.success("添加下载任务成功")
}

// 开始任务
function startTask() {
    console.log(checkedRowKeys.value)
    message.info("开始下载任务")
}

// 停止任务
function stopTask() {
    console.log(checkedRowKeys.value)
}

// 删除任务
function deleteTask() {
    console.log(checkedRowKeys.value)
}

// 清空已完成任务
function clearTask() { }

//  视频合并
function videoMerge() {
    console.log(checkedRowKeys.value)
}

</script>

<style lang="scss" scoped>
.tools {
    height: 100%;
    display: grid;
    grid-template-rows: 60px 1fr 40px;

    .tools-header {
        display: flex;
        align-items: center;
        justify-content: flex-start;

        button {
            margin-left: 10px;
            margin-right: 10px;
        }
    }

    .tools-content {
        overflow: auto;
    }

    .tools-footer {
        padding-left: 20px;
        display: flex;
        align-items: center;
        justify-content: flex-start;
    }
}
</style>