<template>
    <div class="record">
        <n-layout-header bordered class="record-header">
            <n-popover trigger="hover">
                <template #trigger>
                    <n-button circle @click="addTask">
                        <n-icon size="18">
                            <Add />
                        </n-icon>
                    </n-button>
                </template>
                <span>添加录制任务</span>
            </n-popover>
            <n-popover trigger="hover">
                <template #trigger>
                    <n-button circle @click="addBatchTask">
                        <n-icon size="18">
                            <MoreFour />
                        </n-icon>
                    </n-button>
                </template>
                <span>批量添加录制任务</span>
            </n-popover>
            <n-popover trigger="hover">
                <template #trigger>
                    <n-button circle @click="startTask">
                        <n-icon size="18">
                            <PlayOne />
                        </n-icon>
                    </n-button>
                </template>
                <span>开始录制</span>
            </n-popover>
            <n-popover trigger="hover">
                <template #trigger>
                    <n-button circle @click="stopTask">
                        <n-icon size="18">
                            <Pause />
                        </n-icon>
                    </n-button>
                </template>
                <span>停止录制</span>
            </n-popover>
            <n-popover trigger="hover">
                <template #trigger>
                    <n-button circle @click="deleteTask">
                        <n-icon size="18">
                            <Delete />
                        </n-icon>
                    </n-button>
                </template>
                <span>删除任务</span>
            </n-popover>
            <n-popover trigger="hover">
                <template #trigger>
                    <n-button circle @click="clearTask">
                        <n-icon size="18">
                            <Clear />
                        </n-icon>
                    </n-button>
                </template>
                <span>清空已完成任务</span>
            </n-popover>
        </n-layout-header>
        <n-layout-content class="record-content" :native-scrollbar="false">
            <n-data-table striped :columns="columns" :data="data" :pagination="false" :bordered="false"
                :row-key="(row) => row.key" @update:checked-row-keys="handleCheck" />
        </n-layout-content>
        <n-layout-footer bordered class="record-footer">
            log
        </n-layout-footer>
    </div>
    <AddRecord v-model="showModal" @addTaskConfirm="addTaskConfirm" />
</template>

<script setup>
import { ref } from 'vue'
import { NButton, useMessage } from 'naive-ui'
import { Add, MoreFour, PlayOne, Pause, Delete, Clear, MergeCells } from '@icon-park/vue-next'
import AddRecord from '../components/addRecord.vue'

const message = useMessage()

const data = ref([
    { key: "uuid1", name: "Wonderwall", speed: "1Mbps", status: "录制中", remainder: "12:04:18" },
    { key: "uuid2", name: "Don't Look Back in Anger", speed: "1Mbps", status: "录制中", remainder: "4:48" },
    { key: "uuid3", name: "Champagne Supernova", speed: "0Mbps", status: "合并中", remainder: "0:00" },
    { key: "uuid4", name: "I love you", speed: "0Mbps", status: "已完成", remainder: "0:00" }
])

const columns = [
    { type: "selection" },
    {
        title: "名称", key: 'name', align: "left", minWidth: 200,
        ellipsis: {
            tooltip: true
        }
    },
    { title: "速度", key: 'speed', width: 100, align: "center" },
    { title: "状态", key: 'status', width: 100, align: "center" },
    { title: "录制时间", key: 'remainder', width: 100, align: "center" }
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
.record {
    height: 100%;
    display: grid;
    grid-template-rows: 60px 1fr 40px;

    .record-header {
        display: flex;
        align-items: center;
        justify-content: flex-start;

        button {
            margin-left: 10px;
            margin-right: 10px;
        }
    }

    .record-content {
        overflow: auto;
    }

    .record-footer {
        padding-left: 20px;
        display: flex;
        align-items: center;
        justify-content: flex-start;
    }
}
</style>